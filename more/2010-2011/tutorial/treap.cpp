void split(treap* &t, int x, treap* &l, treap* &r){
  if(t==null){ 
    l = r = NULL;
    return ;
  }else{
   if(t->x <= x){
     l = t;
     split(t->r, x, l->r, r);
   }else{
     r = t;
     split(t->l, x, l, r->l);
   }
  }
}

int merge(treap* l,treap* r){
  if(l==NULL) return r;
  if(r==NULL) return l;
  if(l->y > r->y){
    l->r = merge(l->r,r);
    return l;
  }
  r->l = merge(l,r->l);
  return r;
}

struct treap{
  int x, y;
  treap* l,r;
  treap(){ x=y=0; l=r=NULL; }
  treap(int x1, int y1){
    x = x1;
    y = y1;
    l=r=NULL;
  }
};

treap* insert( treap* t, treap* n){
  if(t==NULL){
    return n;
  }
  if( n.y > t.y ){
    split(t,n->x, n->l, n->r);
    return n;
  }
  if(n->x >= t->x){
    return insert(t->r,n);
  }else{
    return insert(t->l,n);
  }
}

treap* erase(treap* t, int x){
  if( t->x == x ){
    ans = merge(t->r, t->l);
    delete t;
    return ans;
  }
  if(x < t->x){
    t->l = erase(t->l, x);
  }else{
    t->r = erase(t->r, x);
  }
}