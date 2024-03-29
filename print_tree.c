 "print_tree.h"

void print_in_dot(t_tree *node,int i, int *count, FILE *fp) 
{
    if (node == nullptr)
        return;
    int node_id = ++(*count);
    fprintf(fp, "  node%d [label=\"%s \"];\n", node_id, (char *)node->value);
    if (i != -1){
        fprintf(fp, "  node%d -> node%d;\n",i,node_id);
    }
    print_in_dot(node->left,node_id,count, fp);
    print_in_dot(node->right,node_id,count, fp);
}

void print_tree(t_tree *root)
 {
	FILE *fp;
	int count;

	count = 0;
	fp = stdout;    
    	/*
     		* u can override fp with fopen system function like in this example:
     		* fp = fopen("filename", "w");
    	*/
    	if (fp == nullptr){
    		fprintf(stderr,"%s\n", strerror(errno));
		exit(1);
    	}
    	fprintf(fp, "digraph {\n");
    	print_in_dot(root, -1, &count, fp);
    	fprintf(fp, "}\n");
	// fclose(fp);
}
