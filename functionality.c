#include "functionality.h"
#include <math.h>
//void load_files(e_news *list);
int compare_string(char a[], char b[]){
    int i =0;
    while(a[i] == b[i]){
        if(a[i]== '\0' && b[i] == '\0') break;
        i++;
    }
    if(a[i]== '\0'&& b[i] == '\0') return true;
    else return false;
}

e_news get_news(char *f){
   
    FILE *file;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char text[100];
    // 
    strcpy(text,"./enews/");
    strcat(text,f);    
    //strcat(text,f);
    file = fopen(text,"r");   
    if(file == NULL) exit(-1);
    char *get_row;
    e_news news ;
    news.no = 0;
    while ((read = getline(&get_row, &len, file)) != -1){
        int len = strlen(get_row);
        if(get_row[len-1]==10) get_row[len-1]= 0;
        news.tag_list[news.no] = get_row;
        news.no +=1; 
        get_row =0;       
    }
    fclose(file);
    return news;
}

int scan_dir(e_news *elist){
    
    //struct dirent * entry;
    DIR *d = opendir( "./enews" );

    if (d == 0) {
        perror("opendir");
        return;
    }
    char *dir[1000];
    int length =0;
    int dir_le= 0;
    while ((dir[dir_le] = readdir(d)->d_name) != 0) {
        if (!(compare_string(dir[dir_le] , ".") == true || compare_string(dir[dir_le] ,"..") == true)){            
            //printf("%s",dir[dir_le]);  
            elist[length] = get_news(dir[dir_le]);
            length++;
            //printf("%s",dir[dir_le]);
            //printf("%i", enews_no[*e_num]);
        }

        if(compare_string(dir[dir_le] ,"..") == true) break;
        dir_le++;      
    }
    
    closedir(d);
    return length;
}

// enews and V management

int data_management(e_news* enews_list,taglist*list){    
    size_t enews_no = scan_dir(enews_list);
    *enews_list[0].full_content = "The first of our three brains to evolve is what scientists call the reptilian cortex. This brain sustains the elementary activities of animal survival such as respiration, adequate rest and a beating heart. We are not required to consciously “think” about these activities.The reptilian cortex also houses the “startle centre”, a mechanism that facilitates swift reactions to unexpected occurrences in our surroundings. That panicked lurch you experience when a door slams shut somewhere in the house, or the heightened awareness you feel when a twig cracks in a nearby bush while out on an evening stroll are both examples of the reptilian cortex at work. When it comes to our interaction with others, the reptilian brain offers up only the most basic impulses: aggression, mating, and territorial defence. There is no great difference, in this sense, between a crocodile defending its spot along the river and a turf war between two urban gangs.";
    *enews_list[1].full_content = "Although the lizard may stake a claim to its habitat, it exerts total indifference toward the well-being of its young. Listen to the anguished squeal of a dolphin separated from its pod or witness the sight of elephants mourning their dead, however, and it is clear that a new development is at play. Scientists have identified this as the limbic cortex. Unique to mammals, the limbic cortex impels creatures to nurture their offspring by delivering feelings of tenderness and warmth to the parent when children are nearby. These same sensations also cause mammals to develop various types of social relations and kinship networks. When we are with others of “our kind” – be it at soccer practice, church, school or a nightclub – we experience positive sensations of togetherness, solidarity and comfort. If we spend too long away from these networks, then loneliness sets in and encourages us to seek companionship";
    *enews_list[2].full_content = "Only human capabilities extend far beyond the scope of these two cortexes. Humans eat, sleep and play, but we also speak, plot, rationalise and debate finer points of morality. Our unique abilities are the result of an expansive third brain – the neocortex – which engages with logic, reason and ideas. The power of the neocortex comes from its ability to think beyond the present, concrete moment. While other mammals are mainly restricted to impulsive actions (although some, such as apes, can learn and remember simple lessons), humans can think about the “big picture”. We can string together simple lessons (for example, an apple drops downwards from a tree; hurting others causes unhappiness) to develop complex theories of physical or social phenomena (such as the laws of gravity and a concern for human rights).";
    *enews_list[3].full_content = "The neocortex is also responsible for the process by which we decide on and commit to particular courses of action. Strung together over time, these choices can accumulate into feats of progress unknown to other animals. Anticipating a better grade on the following morning’s exam, a student can ignore the limbic urge to socialise and go to sleep early instead. Over three years, this ongoing sacrifice translates into a first class degree and a scholarship to graduate school; over a lifetime, it can mean groundbreaking contributions to human knowledge and development. The ability to sacrifice our drive for immediate satisfaction in order to benefit later is a product of the neocortex. ";
    *enews_list[4].full_content = "Understanding the triune brain can help us appreciate the different natures of brain damage and psychological disorders. The most devastating form of brain damage, for example, is a condition in which someone is understood to be brain dead. In this state a person appears merely unconscious – sleeping, perhaps – but this is illusory. Here, the reptilian brain is functioning on autopilot despite the permanent loss of other cortexes. ";
    *enews_list[5].full_content = "Disturbances to the limbic cortex are registered in a different manner. Pups with limbic damage can move around and feed themselves well enough but do not register the presence of their littermates. Scientists have observed how, after a limbic lobotomy2, “one impaired monkey stepped on his outraged peers as if treading on a log or a rock”. In our own species, limbic damage is closely related to sociopathic behaviour. Sociopaths in possession of fully-functioning neocortexes are often shrewd and emotionally intelligent people but lack any ability to relate to, empathise with or express concern for others. ";
    *enews_list[6].full_content = "One of the neurological wonders of history occurred when a railway worker named Phineas Gage survived an incident during which a metal rod skewered his skull, taking a considerable amount of his neocortex with it. Though Gage continued to live and work as before, his fellow employees observed a shift in the equilibrium of his personality. Gage’s animal propensities were now sharply pronounced while his intellectual abilities suffered; garrulous or obscene jokes replaced his once quick wit. New findings suggest, however, that Gage managed to soften these abrupt changes over time and rediscover an appropriate social manner. This would indicate that reparative therapy has the potential to help patients with advanced brain trauma to gain an improved quality of life. ";
    int check = false; 
    for(int j=0;j<enews_no;j++){
        for(int i =0;i<enews_list[j].no;i++){
            //printf("%s \n",enews_list[j].tag_list[i]);
        }
    }
    
    for(int i = 0;i < enews_no;i++){
        for(int j =0; j < enews_list[i].no;j++){
            list->list[list->no] = "\0";
            for(int k = 0; k < list->no;k++){
                if(compare_string(enews_list[i].tag_list[j],list->list[k]) == true ) {
                    check = true;
                    break;
                }
            }
            if(check == false){
                list->list[list->no] = enews_list[i].tag_list[j];
                //printf("%s \n", list->list[list->no]);
                list->no++;
            }else check = false;
        }
    }
    return enews_no;
}

//check similarity

// sub func for check simi

float cal_similarity(int*a,int*b,int dim){
    float len_a = 0 ,len_b = 0;
    int sum=0;    
    for(int i =0;i<dim;i++){
        sum += a[i]*b[i]; // scalar pro
        len_a += a[i]*a[i];//it is 1 though.~~
        len_b += b[i]*b[i];// same here~~
    }
    len_a = sqrtf(len_a);
    len_b = sqrtf(len_b);
    return sum/(len_a*len_b);
}

float check_similarity(e_news *enews_list,taglist *list,size_t enews_no,int e0,int e1){
    int *check0,*check1;
    check0 = malloc(list->no*sizeof(int));
    check1 = malloc(list->no*sizeof(int));
    memset(check0,false,list->no*sizeof(int));
    memset(check1,false,list->no*sizeof(int));
    // check matching of enews 0
    for(int k = 0;k<list->no;k++){
        for(int i = 0;i<enews_list[e0].no;i++){
            if(compare_string(list->list[k],enews_list[e0].tag_list[i])){
                check0[k]=true;
                //printf("%s        ",enews_list[0]->tag_list[i]);
            }
        }
    }
    //check matching of enews 1
    for(int k = 0;k<list->no;k++){
        for(int i = 0;i<enews_list[e1].no;i++){
            if(compare_string(list->list[k],enews_list[e1].tag_list[i])){
                check1[k]=1;
                //printf("%s        ",enews_list[0]->tag_list[i]);
            }
        }
    }

    ///
    float sim = cal_similarity(check0,check1,list->no);
    //printf("%.4f\n",sim);
    for(int i=0;i<list->no;i++){
        //printf("%-30s:  %-5i:%i\n",list->list[i],check0[i],check1[i]);
    }


    return sim;
}

void recommendation(){
    e_news *enews_list =malloc(100*sizeof(e_news));
    taglist *list =malloc(100*sizeof(taglist));
    int enews_no = data_management(enews_list,list);
    int e0 =6;
    for(int i = 0;i< enews_no;i++){
        if(i != e0){
            float sim = check_similarity(enews_list,list,enews_no,e0,i);
            printf("%i to %i  %0.4f\n",i,e0,sim);
        }
    }
}