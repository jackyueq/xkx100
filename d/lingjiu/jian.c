// room: /d/lingjiu/jian.c
// modified by rocwood
#include <ansi.h>
inherit ROOM;
void init();
int do_zou(string);
int do_jump(string);
string check_tiesuo();
void create()
{
	set("short","���ɽ�");
	set("long",@LONG
ɽ������ͻȻ��ʧ��������ǰ��һ��ɽ��(shanjian)��ɽ��֮����
�����ƣ�������޷�������档һ������(tiesuo)�������У��Ա���һ
��ʯ��(bei)��
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"southdown" : __DIR__"yan",
	]));
	set("objects",([
		__DIR__"npc/yupopo" : 1,
	]));
	set("item_desc",([
		"shanjian" : "ɽ��֮���������ƣ�������޷�������棬Ҳ�����������(jump)��ȥ��\n",
		"bei"      : "�����չ����صأ�����������\n",
		"tiesuo"   : (: check_tiesuo :),
	]));
	set("coor/x", -51010);
	set("coor/y", 30010);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_zou", "zou");
	add_action("do_jump","jump");
}
int do_zou(string arg)
{
	object me=this_player(), room;
	if(!arg || arg!="tiesuo") return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy()) return notify_fail("����æ���ء�\n");
	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' ����ʦ����\n");
	if(objectp(present("yu popo", environment(me))))
	{
		if ((string)me->query("family/family_name")!="��ң��"
		&& (string)me->query("family/family_name")!="���չ�"
		)
			message_vision("������������ס$N��˵���������������֮���������ɽ���\n�����չ�������أ���\n",me);
		else
		{
			message_vision(HIW"$N����Ծ������������������������ȥ��\n\n"NOR,me);
			me->move(room);
		}
	}
        else message_vision("$N���Ŷϵ������������������ô��ȥ�أ�\n",me);
        return 1;
}
int do_jump(string arg)
{
	object me=this_player(), room, room1;
	int n = (int)this_player()->query_skill("dodge",1);
	if(!arg || arg!="shanjian") return notify_fail("��Ҫ����������\n");
	if (me->is_busy()) return notify_fail("����æ���ء�\n");
	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' ����ʦ����\n");
	if(!( room1 = find_object(__DIR__"shanjiao")) )
		room1 = load_object(__DIR__"shanjiao");
	if(!objectp(room1))
		return notify_fail("ERROR:not found 'shanjiao.c' ����ʦ����\n");
	if(objectp(present("yu popo", environment(me))))
		message_vision("��ʲôɵ�����������������߹�ȥ����ʲô��ѽ��\n", me);
	else
		if ((string)me->query("family/family_name")=="��ң��")
		{
			message_vision( HIW"$N����һ˦���������չ������Ṧ������Ծ�������������Ʈȥ��\n\n"NOR,me);
			me->move(room);
		}
		else
		{
			message_vision( HIW"$N�����Ṧ�������Ծȥ��\n"NOR,me);
			message_vision( HIW"���Ͼ���ɽ�������൱Զ��$Nһ�������᲻�������ۿ���ɽ�µ���ȥ��\n"NOR,me);
			if(n>100)
			{
				message_vision( HIY"$N�������ǣ�ץס���洹�µ���һ�ض���������������Ծȥ��\n"NOR,me);
				message_vision(HIY"$N�����е������գ�\n"NOR,me);
				me->move(room);
			}
			else
			{
				message_vision(HIR"$N��æ���ң������̶��Ĳҽ�����\n"NOR, me);
				message_vision(HIR"$N���صص�����ɽ���¡���\n\n"NOR, me);
				me->move(room1);
				me->receive_damage("qi", 500);
				me->receive_wound("qi", 500);
			}
		}
	return 1;
}
string check_tiesuo()
{
	object me=this_player();
	if((objectp(present("yu popo", environment(me)))))
		return "����ͨ������ġ������š�����Ҳ������߹�(zou)ȥ��\n";
	else return "���������Ѿ����ˣ���ô��ȥ�أ�\n";
}

