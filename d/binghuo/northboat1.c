// Room: /binghuo/boat1.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����Φ��������֪������˭������ǰ����Φ���˰׷���׼
�����������в��б�����ˮ���㹻֧�ð��ꡣ����ˮ�ָ��������ư͡�
��Φ(gui) ����һ����������粻ס�趯��
LONG );
	set("outdoors", "lingshe");
	set("item_desc", ([
		"gui" : "�����ϵ���Φ�����Թҷ���\n",
	]));
	set("exits", ([
		"out" : __DIR__"lingshegang",
	]));
	setup();
}

void init()
{
	add_action("do_gua", "gua");
	add_action("do_gua", "hang");
}
int do_gua ( string arg )
{
	object ob ;
	string dir;
	if( !arg || (arg !="fan" && arg != "fan bu")) 
	{
		tell_object(this_player() , "��Ҫ��ɶ�أ�Ϲ���ڣ�\n" ) ;
		return 1 ;
	}
	ob = this_player ();
	if (!(present("fan bu", ob)))
	{
		tell_object(this_player() , "�������ģ�������һ����û���ţ�\n");
		return 1 ;
	}
	message_vision("$N������������ͷ����ת�����򱱺��С�\n", ob);
	ob ->move(__DIR__"northboat2") ;
	tell_object(ob, BLU "����һ����Ӳտ��д��˽�������е�������.......\n" NOR ) ;
	call_out("north1", 10 , ob );
	return 1 ;
}
void north1( object ob )
{
	tell_object(ob , BLU
"ͻȻ֮�䣬������һ�࣬���˼���ת��������ˮ��ͬʱ��У�
���������ּ��ż����Х�����˺��֮�����ƺ�ǧ�ٸ�����ͬ
ʱϮ������ֻ��ȫ��һ�������б���ȫ����ˮ������������վ
�𡣽ŵ��²հ嶷Ȼ�������ȥ�����еĺ�ˮ�����⵹к����
���ÿ���Х�����ܾ��Ǻ�ˮ��
    �������������������������죬��Φ��ǰΦ�Ⱥ��۶ϡ���
��Φ�˴��Ű׷������뺣�С�\n" NOR);
	ob->move (__DIR__"northboat3") ;
	tell_object(ob , BLU
"����һ����ͷ�˽����������������һ�½�ʵ��ˮǽ�����һ
�����죬ֻ��ô�ľ��ɡ�\n" NOR) ;
	if (ob->query("neili") < 300)
	{
		tell_object(ob , HIR
"\n�����һ�����˷ɵ�������������֮�⡣�����ͷ���ü���
ͻأ����ȫȻ��⧲����������þ���������������գ���һ��
��ȥ���ŵױ������ɺ���......\n" NOR) ;
		ob->unconcious();
		ob->move("/d/quanzhou/haigang");
	}
	else call_out("north2", 10 , ob);
}
void north2( object ob )
{
	tell_object(ob , BLU
"���ϵĲոǡ��װ����������鲻��������ȴ������ͷ����
�����죬������ע�������ﲨ��ɽ�����⵱�������ֲ�������
����������һʱ���ϸ�ɽ��Ƭ�̼���к��ȣ�Φ�ɾ��ۣ���ֻ
Ҳ���޷���ʻ��\n" NOR);
	ob->move (__DIR__"northboat4") ;
	tell_object(ob , BLU
"����һֱ�򱱣����Ŵ�ֻ��ҹ��ͣ�ı�ʻ��ҹ������������
��ͷ֮ǰ��˸��̫�����������Ϸ����������Ϸ����£�����
ʮ���գ�����ʼ�ղ��䡣\n" NOR);
	call_out("north3", 10 , ob );
}
void north3( object ob )
{
	tell_object(ob , BLU
"����ȴһ����ĺ�����������Ҳһ���һ���㲡��ۿ�������
�������գ��Ƕ����㲻�ɡ�\n"NOR);
	call_out("north4", 10 , ob );
}
void north4( object ob )
{
	tell_object(ob , BLU
"�⴬��ҹ��ͣ����ʻȥ��Խ��Խ�䣬�˿̺��г���СС�����
�պ��Ʊ������Ǳ�������һ����ס���ƶ����ã��Ǳ��������
֮ʱ�ˡ�ֻ�����Ŷ��������������黥��ײ����������һҹ��
�¡�\n"NOR);
	call_out("north5", 10 , ob );
}
void north5( object ob )
{
	tell_object(ob , BLU
"�������磬���ϱ���������ڴ�С��ײ�ڴ��ϣ��������졣��
�渡���������棬����С�ݣ������ú��һ�����죬�������
�𶯡�\n" NOR) ;
	if (random(5) > 2)
	{
		ob->move (__DIR__"ice1") ;
		tell_object(ob , BLU
"�㱻���ڱ�ɽ֮�ϣ�����ײ�ƵĶ�������ֻһ�ٷ�ʱ�ֱ���
������Ӱ���١�\n" NOR);
	}
	else
	{
		tell_object(ob , HIY "�㱻ײ�����˹�ȥ......\n" NOR);
		ob->unconcious();
		ob->move ("/d/beijing/haigang");
	}
}
