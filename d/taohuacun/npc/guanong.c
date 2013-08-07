
inherit __DIR__"changer.c";

int ask_for_y();

int yingtao = 1;

void  create()
{
	set_name("��ũ", ({ "gua nong" }));
	set("gender", "����");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/cuke",
        	__DIR__"obj/carrot",
        	__DIR__"obj/donggua",
        	__DIR__"obj/bean",
        }));	
        set("want_goods", ({
        	__DIR__"obj/chop",
        	__DIR__"obj/hen",
        }));	
        set("inquiry", ([
        	"ӣ��"	: (: ask_for_y :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

int  ask_for_y()
{
	object me = this_player(), ob;
	
	if ( yingtao == 0 || random(me->query("kar")) < 10 ) 
                command( "say ������̫�٣�ӣ�����Ѿ������ˡ�" );
	else {
		command( "say ���Լ��Ե�ӣ�����������ˣ�ժ������һ���ǡ�" );
		command( "say ��Ȼ��λ" + RANK_D->query_respect(me) + "�����ˣ�������һЩ�ɡ�" );
		message_vision( "��ũ�����ﵹ��һЩӣ�ҳ����͸�$N��\n", me );
		ob = new( __DIR__"obj/yingtao" );
		ob->move( me );
		yingtao = 0;
	}
	return 1;
}
