// ahda.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "xiyi" }));
	set("title", "��乤��Ʒ�����");
	set("shen_type", 1);

	set("gender", "����" );
	set("long", @LONG
������һ������������������ҡ���ȣ������ͷ΢Ц��
LONG);
	set("nickname", HIY"������Ԫǰ"NOR);
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	setup();

        carry_object(__DIR__"obj/pen")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}