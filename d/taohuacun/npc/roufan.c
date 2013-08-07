
inherit __DIR__"changer.c";

int  ask_for_y();
int  ask_for_z();
int  ask_for_n();

int  zuotun = 1;
int  yaozi = 1;
int  erduo = 1;

void  create()
{
	set_name("�ⷷ", ({ "rou fan" }));
	set("gender", "����");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/chop",
        	__DIR__"obj/hen",
        	__DIR__"obj/cock",
        	__DIR__"obj/meat",
        	__DIR__"obj/beef",
        }));	
        set("want_goods", ({
        	__DIR__"obj/baicai",
        	__DIR__"obj/qingcai",
        }));	
        set("inquiry", ([
        	"�������"  :  (: ask_for_y :),
        	"Сţ����"  :  (: ask_for_n :),
        	"С�����"  :  (: ask_for_z :),
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
	
	if ( zuotun == 1 && random(me->query("kar")) > 10 ) {
		command( "say �������ˣ��������ʣ��һ�飬�͸���ɡ�" );
		message_vision( this_object()->query("name") + "�ó�һ��������εݸ�$N��\n", me );
		ob = new( __DIR__"obj/zuotun" );
		ob->move( me );
		zuotun = 0;
	}	
	else 
		command( "say ������̫�٣�������ΰ��������ˡ�" );
	return 1;
}

int  ask_for_n()
{
	object me = this_player(), ob;
	
	if ( yaozi == 1 && random(me->query("kar")) > 10 ) {
		command( "say �ⶫ���ɲ���Ū�������������˵ķ��Ͼ͸���һ���ɡ�" );
		message_vision( this_object()->query("name") + "�ó�һ��Сţ���ӵݸ�$N��\n", me );
		ob = new( __DIR__"obj/yaozi" );
		ob->move( me );
		yaozi = 0;
	}	
	else 
		command( "say ������̫�٣�Сţ���Ӱ��������ˡ�" );
	return 1;
}

int  ask_for_z()
{
	object me = this_player(), ob;
	
	if ( erduo == 1 && random(me->query("kar")) > 10 ) {
		command( "say �������������Ҳû�ã���Ҫ����ȥ��" );
		message_vision( this_object()->query("name") + "�ó�һ��С�����ݸ�$N��\n", me );
		ob = new( __DIR__"obj/erduo" );
		ob->move( me );
		erduo = 0;
	}	
	else 
		command( "say ������̫�٣�С����䰳�������ˡ�" );
	return 1;
}