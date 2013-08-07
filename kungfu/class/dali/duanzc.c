// duanzc.c ������
//last modified 01/05/05

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	object ob;
	set_name("������", ({ "duan zhengchun", "duan" }));
	set("title",  "����������" );
	set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	set("no_get",1);

        set("inquiry", ([
                  "�ؼ�"     : (: ask_me :),
                  "�μҸ���"  : (: ask_me :),
                  "shu" : (: ask_me :),
                       ]));
	
	set("max_qi", 2200);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 300000);
        set("book_count",1);
       
        set_skill("force", 150);
        set_skill("axe", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("finger", 120);
	set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 210);
        set_skill("duanyun-fu", 210);
        set_skill("jinyu-quan", 220);
        set_skill("wuluo-zhang", 220);
        set_skill("duanjia-sword", 225);
        set_skill("sun-finger", 180);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("axe", "duanyun-fu");
	map_skill("staff", "duanjia-sword");
	prepare_skill("finger", "sun-finger");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "axe.duan" :),
                (: perform_action, "axe.hongtianza" :),
                (: perform_action, "axe.tiaoyan" :),			
		(: perform_action, "finger.qiankun" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	if (clonep())
	{
	 ob=new(WEAPON_DIR"treasure/duanyun-axe");
   if ( ob->violate_unique() )
   {
     destruct(ob);
     ob = new(WEAPON_DIR"axe");
   }
   ob->move(this_object());
   ob->wield();
 }
add_money("silver", 50);

	create_family("����μ�",18,"������");
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("kurong-changong",1) < 100 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	if (strsrch(ob->query("guard"), "��������") >= 0) 
	{
		command("say �ܺã���Ȼ���������͵�����Ϊ����");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say ���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
		return;
	}
}
string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="duan zhengchun")
		return RANK_D->query_respect(this_player()) + 
		"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/axe");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ��μҸ�������\n");
	return "�ðɣ��Ȿ���μҸ��������û�ȥ�ú����У�����Ҵ���μ���ѧ��";
}
