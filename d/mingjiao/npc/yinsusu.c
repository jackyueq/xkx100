// Yinsusu.c

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_me();
int decide();
void goto_wpsd1(object me);
void goto_wpsd2(object me);
#include <ansi.h>

void create()
{
	set_name("������", ({ "yin susu", "yin", "susu", }));
	set("long","���ǰ�üӥ���Ķ���Ů���ְ�ʤѩ�����΢�ݣ�ü���ͦ��һЦʱ
�����ǳǳһ�����С�\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "fighert");

	set("age", 18);
	set("shen_type", 1);
	set("per", 29);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang-quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	set("inquiry", ([
		"лѷ"      : (: ask_me :),
		"����"    : (: ask_me :),
		"������"    : (: ask_me :),
		"��ëʨ��"  : (: ask_me :),
		"��üӥ��"  : "�����ҵ���",
	]));
	prepare_skill("cuff", "jingang-quan");

	set("party/party_name",HIG"����"NOR);
	set("party/rank",HIM "��΢��" NOR "����");
	create_family("����", 35, "����");
	setup();

	carry_object("/d/yanziwu/npc/obj/green_cloth")->wear();
}

void init()
{
	add_action("do_decide", "decide");
}

int ask_me()
{
	object me;
	me = this_player ( ) ;
	message_vision(
"�������������´�����$Nһ�£�������λ"+RANK_D->query_respect(me)+"���㲻�������������ɡ�\n��С��Ҳ�������ˣ�����Ҫȥ����ɽ�����㿴��������(decide)Ҫ��Ҫȥ��\n",me);

	me->set_temp ("yinsusu", 1 );
	return 1;
}

int do_decide()
{
	object me;
	me = this_player ( ) ;
	if (me->query_temp("yinsusu") != 1 )
		return notify_fail("�������ʣ������ʲôѽ��\n");

	message_vision("�����ض�$N˵�������ã���ɱ��ڣ������ˡ���\n\n", me);
	message_vision("���������𷫣�С������Ư�򽭿ڡ�\n\n", me);
	me->move ("/d/binghuo/jiangmian1");
	call_out("goto_wpsd1",10,me) ;
       	return 1;
}

void goto_wpsd1(object me)
{
	message_vision("�緫���磬С���ھ����Ư�����ڡ�\n\n", me);
	me->move ("/d/binghuo/jiangmian2");
	call_out("goto_wpsd2",10,me) ;
}

void goto_wpsd2(object me)
{
	tell_object(me , "Ƭ�̼������������׹��������������塣������������\n" ) ;
	me->move ("/d/binghuo/wangpanshan") ;
}

