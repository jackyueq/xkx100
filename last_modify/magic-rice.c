// magic-rice.c
// 1998/12/16 Modified by Winder
// ���ӻ����ļ����а�,zeratul 2000.1.13
// Modified by Zeratul Jan 13 2001 

#define TOPTEN DATA_DIR + "topten"

inherit ITEM;
inherit F_SAVE;

mapping *exp_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *richman_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *oldman_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *force_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *literate_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *pks_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *betrayer_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *thief_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *sword_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *blade_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *unarmed_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *dodge_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *throwing_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *whip_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *hammer_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *staff_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *weapon_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});
mapping *gambling_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});

int savetopten(object);
mapping *restore_exp_topten();

int simple_sort( mapping *,string,int,object );
int simple_sort_skill( mapping *,string,int,object );

int create()
{
        set_name("����", ({ "hero-board","board"}) );
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        set("long", "");
        set("unit", "��");
        set("value", 0);
        setup();
                
        if( restore() )
        {
                exp_topten=query("exp_topten");
                richman_topten=query("richman_topten");
                oldman_topten=query("oldman_topten");
                force_topten=query("force_topten");
                literate_topten=query("literate_topten");
                pks_topten=query("pks_topten");
                betrayer_topten=query("betrayer_topten");
                thief_topten=query("thief_topten");
                sword_topten=query("sword_topten");
                blade_topten=query("blade_topten");
                unarmed_topten=query("unarmed_topten");
                dodge_topten=query("dodge_topten");
                throwing_topten=query("throwing_topten");
                whip_topten=query("whip_topten");
                hammer_topten=query("hammer_topten");
                staff_topten=query("staff_topten");
                weapon_topten=query("weapon_topten");
                gambling_topten=query("gambling_topten");                
        }
	// ���ӳ�ʼ�����а�
	// Modified by Zeratul Jan 13 2001
       	else
       	{
	        set("exp_topten",exp_topten);
	        set("richman_topten",richman_topten);
	        set("oldman_topten",oldman_topten);
	        set("force_topten",force_topten );
	        set("literate_topten",literate_topten );
	        set("pks_topten",pks_topten );
	        set("betrayer_topten",betrayer_topten );
	        set("thief_topten",thief_topten );
	        set("sword_topten",sword_topten );
	        set("blade_topten",blade_topten );
	        set("unarmed_topten",unarmed_topten );
	        set("dodge_topten",dodge_topten );
	        set("throwing_topten",throwing_topten );
	        set("whip_topten",whip_topten );
	        set("hammer_topten",hammer_topten );
	        set("staff_topten",staff_topten );
	        set("weapon_topten",weapon_topten );
	        set("gambling_topten",gambling_topten );        
	}       
        return 1;
}

string query_save_file() { return TOPTEN; }

int savetopten( object me )
{
        object obj;
        int exist,i;

        simple_sort( exp_topten,"combat_exp",10,me );
        simple_sort( richman_topten,"balance",10,me );
        simple_sort( oldman_topten,"mud_age",10,me );
        simple_sort( force_topten,"max_neili",10,me );
        simple_sort_skill( literate_topten,"literate",10,me );
        simple_sort( pks_topten,"PKS",10,me );
        simple_sort( betrayer_topten,"betrayer",10,me );
        simple_sort_skill( thief_topten,"stealing",10,me );
        simple_sort_skill( sword_topten,"sword",10,me );
        simple_sort_skill( blade_topten,"blade",10,me );
        simple_sort_skill( unarmed_topten,"unarmed",10,me );
        simple_sort_skill( dodge_topten,"dodge",10,me );
        simple_sort_skill( throwing_topten,"throwing",10,me );
        simple_sort_skill( whip_topten,"whip",10,me );
        simple_sort_skill( hammer_topten,"hammer",10,me );
        simple_sort_skill( staff_topten,"staff",10,me );
        simple_sort_skill( gambling_topten,"gambling",10,me );
        simple_sort( weapon_topten,"weapon/lv",10,me );

        set("exp_topten",exp_topten);
        set("richman_topten",richman_topten);
        set("oldman_topten",oldman_topten);
        set("force_topten",force_topten );
        set("literate_topten",literate_topten );
        set("pks_topten",pks_topten );
        set("betrayer_topten",betrayer_topten );
        set("thief_topten",thief_topten );
        set("sword_topten",sword_topten );
        set("blade_topten",blade_topten );
        set("unarmed_topten",unarmed_topten );
        set("dodge_topten",dodge_topten );
        set("throwing_topten",throwing_topten );
        set("whip_topten",whip_topten );
        set("hammer_topten",hammer_topten );
        set("staff_topten",staff_topten );
        set("weapon_topten",weapon_topten );
        set("gambling_topten",gambling_topten );

        save();
        return 1;
}

int simple_sort( mapping *which_chart,string chart_type,int chart_size,object me )
{
        int i,exist;
        string *c_id=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
        string si;

        si="����";
        c_id[chart_size] = me->query("id");
        c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
        c_type[chart_size] = me->query(chart_type);
        exist = 0;
        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf("��%d��",i+1 );
                sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
                if( c_id[i] == c_id[chart_size] )
                {
                        c_short[i] = c_short[chart_size];
                        c_type[i]  = c_type[chart_size] ;
                        exist = 1;
                        continue;
                }
//              if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//                      c_type[i]= 0;
        }


        for( i = 0; i < chart_size - exist; i++ )
        {
                if( c_type[i] < c_type[i+1] )
                {
                        c_id[chart_size+1]    = c_id[i];
                        c_short[chart_size+1] = c_short[i];
                        c_type[chart_size+1]  = c_type[i];
                        c_id[i]    = c_id[i+1];
                        c_short[i] = c_short[i+1];
                        c_type[i]  = c_type[i+1];
                        c_id[i+1]    = c_id[chart_size+1];
                        c_short[i+1] = c_short[chart_size+1];
                        c_type[i+1]  = c_type[chart_size+1];
                }

        }

        for( i = chart_size - exist; i > 0; i-- )
                if( c_type[i] > c_type[i-1] )
                {
                        c_id[chart_size+1]    = c_id[i-1];
                        c_short[chart_size+1] = c_short[i-1];
                        c_type[chart_size+1]  = c_type[i-1];
                        c_id[i-1]    = c_id[i];
                        c_short[i-1] = c_short[i];
                        c_type[i-1]  = c_type[i];
                        c_id[i]    = c_id[chart_size+1];
                        c_short[i] = c_short[chart_size+1];
                        c_type[i]  = c_type[chart_size+1];
                }

        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf( "��%d��",i+1 );
                which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
        }

        return 1;
}

int simple_sort_skill( mapping *which_chart,string chart_type,int chart_size,object me )
{
        int i,exist;
        string *c_id=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
        string si;

        si="����";
        c_id[chart_size] = me->query("id");
        c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
        c_type[chart_size] = me->query_skill(chart_type);
        exist = 0;
        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf("��%d��",i+1 );
                sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
                if( c_id[i] == c_id[chart_size] )
               {
                        c_short[i] = c_short[chart_size];
                        c_type[i]  = c_type[chart_size] ;
                        exist = 1;
                        continue;
                }
//              if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//                      c_type[i]= 0;
        }


        for( i = 0; i < chart_size - exist; i++ )
        {
                if( c_type[i] < c_type[i+1] )
                {
                        c_id[chart_size+1]    = c_id[i];
                        c_short[chart_size+1] = c_short[i];
                        c_type[chart_size+1]  = c_type[i];
                        c_id[i]    = c_id[i+1];
                        c_short[i] = c_short[i+1];
                        c_type[i]  = c_type[i+1];
                        c_id[i+1]    = c_id[chart_size+1];
                        c_short[i+1] = c_short[chart_size+1];
                        c_type[i+1]  = c_type[chart_size+1];
                }

        }

        for( i = chart_size - exist; i > 0; i-- )
                if( c_type[i] > c_type[i-1] )
                {
                        c_id[chart_size+1]    = c_id[i-1];
                        c_short[chart_size+1] = c_short[i-1];
                        c_type[chart_size+1]  = c_type[i-1];
                        c_id[i-1]    = c_id[i];
                        c_short[i-1] = c_short[i];
                        c_type[i-1]  = c_type[i];
                        c_id[i]    = c_id[chart_size+1];
                        c_short[i] = c_short[chart_size+1];
                        c_type[i]  = c_type[chart_size+1];
                }

        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf( "��%d��",i+1 );
                which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
        }

        return 1;

}

int movein(object me)
{
        move_object(me);
        return 1;
}
                        


