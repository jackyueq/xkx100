// mengpo.c ����

#include <ansi.h>
#include <login.h>
inherit NPC;

string *death_msg = ({
	HIB "����˵���������ӣ�����������\n\n" NOR,
	HIB "���Ŷ���΢Ц�ţ�˵������Ȼ���ˣ��Ͳ�Ҫ������ˡ���\n\n\n" NOR,
	HIB "����˵�����������䣬��Ҫ����������龡�������źá���\n\n" NOR,
	HIB "����˵�����������ʹ�����ǹ�ȥ��һ�У���������˰ɡ���������\n\n���Ÿ���һ��衣\n" NOR,

});

void create()
{
	set_name("����", ({ "meng po" }) );
	set("long",@LONG
�������ڶ���ĩ�꣬һ��δ����ޣ���ի���ƣ�ֱ����ʮ������Ȼ
���彡�ʣ���ò��������ʮ��һ�㣬��������Ϊ���ɣ�����������ɽ
�������У�������һ����ʮ��ʱ�õ����ɡ����������ʴ������
���������ƹ���˾����
LONG);
	set("gender","Ů��");
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"�����������������ļ�򣬰�ο�㡣\n",
		"����˵�������ӣ�������Ϊʲôɥ���ģ��������š���\n",
	}) );
	set("age", 1024);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	setup();
}

void init()
{
	remove_call_out("tea_give");
	call_out( "tea_give", 3, this_player(),0 );
}

void tea_give(object ob,int stage)
{
	object tea;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "tea_give", 3, ob, stage );
		return;
	}
	if( !objectp( present( GRN"mengpo tea"NOR ,ob ) ) && !objectp( present( GRN"mengpo tea"NOR , environment( this_object() ) ) ) )
	{
		tea = new(NOSTRUM_DIR"mengpotea");
		tea->move(ob); 
	}
}
int accept_fight(object me)
{
	command("sigh");
	write("���ŵ��������ӣ������ǲ��ɾ�ҩ�ˣ���\n");
	kill_ob(me);
	me->fight_ob(this_object());
	return 1;
}

