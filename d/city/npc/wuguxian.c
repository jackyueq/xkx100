// wuguxian.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "�����" NOR,({ "wu guxian", "wu", "teacher"}) );
	set("title", "������Ժ����");
	set("gender", "����" );
	set("age", 55);
	set("long", @LONG
����;�˵������ѧԺ�Ѿ�����ʮ������飬���Ҳ���ˣ����Խ��Խ
�ظ���ѧ�ʺ�����ʱ���Զ�ˣ��ֵ���Ĵ�����������ʼ�ڿΣ�������
������ѧԺ��������һЩ���Ӷ�ͯ����԰��
LONG
	);
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("str", 15);
	set("con", 18);
	set("dex", 20);
	set("per", 21);
	set_skill("literate", 60);
	set("chat_chance", 3);
	set("chat_msg", ({
		"�����̾�������ڵĺ���ѽ��������������\n",
		"����͵��������Ѿ��������ˣ��û��ϼҹ������������ˡ�",
		"�����̾�����̼�ʮ����飬ѧ��ȴԽ��Խ���ˣ�����������",
	}));
	set("inquiry", ([
		 "���" : "��ߣ���ѽ��������ʮ����δ���ˡ�˵�꣬����ͳ�̾һ����",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

