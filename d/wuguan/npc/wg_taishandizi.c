inherit NPC;
#include <ansi.h>

void create()
{
       set_name("̩ɽ����", ({ "taishan dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ��Ӣ����̩ɽ���ӡ�\n");
       set("combat_exp", 12500);
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
			say( "̩ɽ�ɵ���˵������λ" + RANK_D->query_respect(ob)
            + "�����̩ɽ���𣬿��Կ�"BRED"(help taishan)"NOR"��\n");
			break;
		case 1:
			say( "̩ɽ�ɵ���˵��������̩ɽ����ϰ�ý�����Ψһ�ٷ����еľ��С������Ρ���\n");
			break;
		case 2:
			say( "̩ɽ�ɵ���˵����̩ɽ���԰���ǰ������ʦ�������������в��ˣ������Կɰ���������\n");
			break;
	}

}
