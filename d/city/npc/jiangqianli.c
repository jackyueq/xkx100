// npc: /d/city/npc/jiangqianli.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;

void create()
{   
	set_name(YEL "��ǧ��" NOR, ({ "jiang qianli","jiang" }) );
	set("gender", "����");
	set("title", "��������������");
	set("age", 38);
	set("long", @LONG
�������ݳ�����õ������ֹ����ˣ��е���ģ��ķ���������ȥһ�ź�����
ֻ�����ֵ���ָ��ϸ�޳��Գ����Ǹ��ֹ����ˡ�
LONG
	);
	set("attitude", "peaceful");

	set("str", 17);
	set("int", 30);
	set("dex", 30);
	set("con", 30);
	set("per", 20);

	set("combat_exp", 100000);
	set("score", 9000);

	set("inquiry", ([
		"��ǧ��" : "��ǧ������ҡ������ս���ǧ�������ˮ��\n",
		"��ɳ��" : "������������߾���˼����������ʮ��ž��ƾ�����",
		"���䱭" : "������������������һ��ʫ��\n"+
			"			����ױ�����⣬��ϼ�ﳺ������\n"+
			"			���������̫ͨ���������ڵ�����\n",
	]) );


	setup();

}

