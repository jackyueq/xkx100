// xueyuan.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ѩԭ", ({ "xueyuan" }));
	set("title", HIM"����̨����"NOR);
	set("shen_type", 1);

	set("gender", "Ů��" );
	set("long", @LONG
ѩԭ�ú���ֵ��������㡣
LONG);
	set("nickname", HIW"�Դ�û�а�"NOR);
	set("age", 20);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	set("combat_exp", 1000000);
	setup();

	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}