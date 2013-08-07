// yu.c �������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�������", ({ "diancang yuyin", "yu" }));
	set("title",  "�����ˮ������" );
	set("long", 
"�����Ǵ������ԭˮ��������һ�ƴ�ʦ���Ĵ����֮һ��
��ԼĪ��ʮ������ͣ�һ�ź�����Ĺ����������������
����������\n");
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
        set_skill("tiannan-step", 100);
        set_skill("jinyu-quan", 100);
        set_skill("wuluo-zhang", 100);
        set_skill("duanjia-sword", 100);
        set_skill("sun-finger", 100);
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

        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/kungfu/class/dali/obj/diaogan")->wield();
	add_money("silver", 50);

	create_family("����μ�",25,"����");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if( myfam["master_id"] == "yideng dashi")
	{
message_vision(HIY"���������$N˵��������ˡ��Լ���ȥ��ʦ���ɡ�\n"NOR, ob);
		ob->set_temp("yu_allow", 1);
	}
	return;
}

int accept_object(object who, object ob)
{
	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");

	if ( (string)ob->query("id") != "hong bu")
		return notify_fail("�����������Ҫ���������\n");
	say( "�������������˵�ͷ������ȥ�ɡ�\n");
	who->set_temp("yu_allow", 1);
	return 1;
}

