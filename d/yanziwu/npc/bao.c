// bao.c
inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("������", ({ "bao buliang","bao","buliang" }) );
	set("gender", "Ů��" );
	set("age", 6);
	set("long",
"���귽���꣬�۾�һ��һС���ǿ׳��죬�����з磬���������кη�
�������˾��Ʋ����������ޱ�Ц������Ц�ؿޣ�����������ʱ����ͣ��
���ǰ��������ı���Ů����������\n");
	set("shen_type", 1);
	set("combat_exp", 100);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	create_family("����Ľ��", 34, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
