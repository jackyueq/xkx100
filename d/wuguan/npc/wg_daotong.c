
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�䵱��ͯ", ({ "daotong", "tong" }) );
       set("gender", "����" );
       set("age", 16);
       set("long",
               "����һ��ʮ�߰����С��ͯ��һ����������ӡ�\n");
       set("combat_exp", 2500);
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
			say( "�䵱��ͯЦ������˵������λ" + RANK_D->query_respect(ob)
          + "��������䵱�Ļ������Կ�"BRED"(help wudang)"NOR"��\n");          
			break;
		case 1:
			say( "�䵱��ͯ����������ϴο����������Ѿ���һ��ǰ�ˣ����������˼�
 �书���������ɲ��ˣ�����˭�����䵱�ɹ�Ŀ����ء�\n");
			break;
		case 2:
			say( "�䵱��ͯ�����˵�������䵱�ɵ��˲ι�����ľ֮�棬���˶�������Ϊ���кô���\n");
			break;	
	
	}

}
