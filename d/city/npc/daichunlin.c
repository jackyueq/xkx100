// npc: /d/city/npc/daichunlin.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "������" NOR, ({ "dai chunlin", "dai", "chunlin"}) );
    set("title", "����������ϰ�");
    set("age", 42);
    set("long", @LONG
�������ݳ����������̵��ϰ壬�����ģ��ʷ����֣�������ȥ������
�ϣ����˲����׽���
LONG
	);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("combat_exp",10000);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
}

