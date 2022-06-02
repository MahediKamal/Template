lli chk(lli num,lli pos){
    return num & (1<<(pos-1));
}
lli Set(lli num,lli pos){
    return num | (1<<(pos-1));
}
lli reset(lli num,lli pos){
    return num & (~(1<<(pos-1)));
}
