
inherit __DIR__"changer.c";

int ask_for_s();

int sunjian = 1;

void  create()
{
	set_name("��ũ", ({ "old man" }));
	set("gender", "����");
	set("age", 50);
	set("per", 15);
	set("long", "һλɽ�������ϴ�ү��\n");
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/xianggu",
        	__DIR__"obj/lizi",
        }));	
        set("inquiry", ([
        	"���"	:  (: ask_for_s :),
        ]));
        set("want_goods", ({
        	__DIR__"obj/cuke",
        	__DIR__"obj/meat",
        }));	
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

int  ask_for_s()
{
	object me = this_player(), ob;
	
	if ( sunjian == 0 || random(me->query("kar")) < 10 ) 
                  command( "say ������̫�٣�������Ѿ������ˡ�" );
 	else
 	   {
	          command( "say ��ժ�㹽��ʱ��˳��ժ��Щ��⣬��λ" + RANK_D->query_respect(me) + "Ҫ�Ļ����͸�����ˡ�" );
		  message_vision( "��ũ�͸�$Nһ����⡣\n", me );
		  ob = new( __DIR__"obj/sunjian" );
		  ob->move( me );
		  sunjian = 0;
	   }
	return 1;	
}