
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("С����", ({ "xiao heshang", "xiao" }) );
       set("gender", "����" );
       set("age", 16);
       set("long",
               "����һ��ʮ�߰����С���У�һ��ѭ�浸�ص����ӡ�\n");
       set("combat_exp", 10500);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "����С����Ц������˵������λ" + RANK_D->query_respect(ob)
           + "����������ֵĻ������Կ�"BRED"(help shaolin)"NOR"��\n");
			break;
		case 1:
			say( "����С����΢Ц�������¹�������֣����������м�����ȥ
 �������������ǡ���Ħ���洫��������ѧ�����ɲ����Ż��˵ġ�\n");
			break;
	}

}
