// jiang.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "jiang tao", "jiang", "tao" }));
	set("long", 
"������ɫ���ۣ�����б�峤������ʮ�˾�����ͣ����ֺ�˪��һ
��Ҫ�������ǵ�ģ����\n");
	set("gender", "����");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 70000);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("huashan-jianfa", 80);
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	create_family("������", 4, "����");

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="gao zecheng")
                {
                    me->kill_ob(obj[i]);
                }
	}
        return;
}

