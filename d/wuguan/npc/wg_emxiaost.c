
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����Сʦ̫", ({ "xiao shitai", "xiao" }) );
       set("gender", "Ů��" );
       set("age", 16);
       set("long",
               "������һλ���ҵ�Сʦ̫������ü��Ŀ�㡣\n");
       set("combat_exp", 40500);
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
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(3) ) {
		case 0:
			say( "Сʦ̫΢΢Ц��˵�������գ����գ���λ" + RANK_D->query_respect(ob)
          + "��������������ޣ����Կ�"BRED"(help emei)"NOR"��\n");
			break;
		case 1:
			say( "Сʦ̫΢Ц�������ҹ���������أ��ټ�ʮ��ׯΪ�ڹ��еľ�ѧ��
 ���е����ط�������������������\n");
			break;
		case 2:
			say( "Сʦ̫΢Ц�������ܹ�ͨ��ڤ��ׯ��ɵ���������ʿ����������������ᡢ
ˮ��ȼõľ��硢����ͨ�����鵤֮���\n");
			break;	
	}

}
