char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
bool hasntDest = true;
char* nextDest;

for(int i=0; i<pathsSize; i++){
 nextDest = paths[i][pathsColSize[i]-1];
 hasntDest = true;

for(int j=0; j<pathsSize; j++){
if(!strcmp(nextDest, paths[j][0])){
hasntDest=false;
break;
}
}
if(hasntDest)
return nextDest;
}
return nextDest;
}

