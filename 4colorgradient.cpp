const vec4 TLCOLOR = vec4(1.0, 0.0, 0.0, 0.0);
const vec4 TRCOLOR = vec4(0.0, 1.0, 0.0, 0.0);
const vec4 BLCOLOR = vec4(0.0, 0.0, 1.0, 0.0);
const vec4 BRCOLOR = vec4(1.0, 1.0, 0.0, 0.0);
const vec4 CCCOLOR = vec4(-0.01, -0.3, -0.5, 0.0);

const vec2 TL = vec2(0.0, 1.0);
const vec2 TR = vec2(1.0, 1.0);
const vec2 BL = vec2(0.0, 0.0);
const vec2 BR = vec2(1.0, 0.0);


void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    float ccX = abs(sin(iGlobalTime/5.0));
    float ccY = 0.5 + sin(iGlobalTime)/2.0;
    vec2 CC = vec2(ccX, ccY);

    // current secreen coordinates normalized
    vec2 cord;  
    cord.xy = fragCoord.xy / iResolution.xy; 
    
    // normalized distance to screen vertexes
    float dTL = distance(cord, TL);
    float dTR = distance(cord, TR);
    float dBL = distance(cord, BL);
    float dBR = distance(cord, BR);
    float dCC = distance(cord, CC);    
    
    float iTL = (dTL == 0.0 ? 1.0 : 1.0/dTL);
    float iTR = (dTR == 0.0 ? 1.0 : 1.0/dTR);
    float iBL = (dBL == 0.0 ? 1.0 : 1.0/dBL);
    float iBR = (dBR == 0.0 ? 1.0 : 1.0/dBR);
    float iCC = (dCC == 0.0 ? 1.0 : 1.0/dCC);
    
    float sum = iTL + iTR + iBL + iBR + iCC;
    float wTL = (iTL / sum);
    float wTR = (iTR / sum);
    float wBL = (iBL / sum);
    float wBR = (iBR / sum);
    float wCC = (iCC / sum);
    
    vec4 finalColor = 
        (iTL * TLCOLOR *wTL) + 
        (iTR * TRCOLOR *wTR) +
        (iBL * BLCOLOR *wBL) +
        (iBR * BRCOLOR *wBR) +
        (iCC * CCCOLOR *wCC);
      
    fragColor = finalColor;
}
