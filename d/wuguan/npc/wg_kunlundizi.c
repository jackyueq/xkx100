inherit NPC;
#include <ansi.h>

void create()
{
       set_name("���ص���", ({ "kunlun dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ���뺷�����ص��ӡ�\n");
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
			say( "�����ɵ���˵������λ" + RANK_D->query_respect(ob)
            + "������������𣬿��Կ�"BRED"(help kunlun)"NOR"��\n");
			break;
		case 1:
			say( "�����ɵ���˵����ϰ�ñ���ȭ��˫��������Ц�����֡�\n");
			break;
		case 2:
			say( "�����ɵ���˵������ʦ��������ʥ�����������˫ȫ����ǹ��ꪣ�ȭ������������
�黭��ʫ��ʸ�����һ����ݹŽ񣬹ھ����¡�\n");
			break;
	}

}
