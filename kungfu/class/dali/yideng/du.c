// du.c ����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_reply1();
string ask_reply2();
string ask_reply3();

void create()
{
	set_name("������", ({ "zhu ziliu", "zhu", "ziliu" }));
	set("title",  "�����������" );
	set("long", 
"�����Ǵ������ԭ�����࣬һ�ƴ�ʦ���Ĵ����֮һ��
ֻ������ʮ������ͣ�ͷ����ң���ֻ��۵��ȣ����
һ����ڵĳ��룬ȷ�Ǹ���ѧ����ģ����\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 10000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("staff", 100);
        set_skill("finger", 100);
	set_skill("kurong-changong", 100);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("wuluo-zhang", 150);
        set_skill("duanjia-sword", 150);
        set_skill("sun-finger", 150);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.qiankun" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档�����˾Ϳ��Լ����ˡ�\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
                "��δ״Ԫ"   : (: ask_reply1 :),
                "˪���Ҷ�����Ź����ң��"   : (: ask_reply2 :),
                "�������ˣ���С����Զǳ�"   : (: ask_reply3 :),
        ]) );

        set("chat_chance", 3);
        set("chat_msg", ({
"��������������ĺ���ߣ������ȳɣ����������ˣ�ͯ�������ˣ�ԡ
���ʣ����������ӽ���顣�������˸߲��ң�һ����̾��ȷ���ڴ�
�����ظ����裬ϲ�����ѡ�\n",
"����������������
    �������̼����оã�һ��ʮ��ĥ���֡�
      �ӻ�ͷ��һ֦�ᣬ��й���Ī¶�ڡ�
      һ�����۴��綷��ȴ�ڰ봲�����С�
      ����ֱ���ҹڹ飬������Ŀ��֪�񣿡�\n",
"����������ָ��һ����鵵����������鵣�ǧ�ַ�ҡ�۵��ȡ���\n",
"����������������һ��������Ը�����������ɪ���ã��˴���һ��ͷ�桯����\n",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/book/lbook4");
	add_money("silver", 50);

	create_family("����μ�",25,"����");
}


void greeting(object ob)
{
        mapping myfam;

        myfam = (mapping)ob->query("family");
        if( myfam["master_name"] == "yideng dashi")
              say ("��������������˵�ͷ��˵��������ˡ�\n");
	ob->set_temp("du_allow", 1);
        return;
}

string ask_reply1()
{
	object me = this_player();
	me->set_temp("yideng_du1", 1);
	if (me->query_temp("yideng_du2") && me->query_temp("yideng_du3"))
	{
message_vision("\n�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "�롣";
	}
	else
		return RANK_D->query_respect(me) + "��Ȼ����ȫ�š����������أ�";
}
string ask_reply2()
{
	object me = this_player();
	me->set_temp("yideng_du2", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du3"))
	{
message_vision("\n�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "�롣";
	}
	else
		return RANK_D->query_respect(me) + "��Ȼ����ȫ�š����������أ�";
}
string ask_reply3()
{
	object me = this_player();
	me->set_temp("yideng_du3", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du2"))
	{
message_vision("\n�������󾪣�վ������������һ�ӣ���$NһҾ���أ�˵���������°ݷ�����\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "�롣";
	}
	else
		return RANK_D->query_respect(me) + "��Ȼ����ȫ�š����������أ�";
}
