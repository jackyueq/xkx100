// tiji.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�콾", ({ "tiji"}));
	set("gender", "����");
	set("class", "bonze");
	set("title", HIR"ѧʿ"HIG"����"HIC"�����Ž���"NOR"��������֮һ���콾���������Ŵ�ʦ��"NOR);
	set("nickname", HIY"��Ʒ�Ӱӡ����"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("������" ,37, "����");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
