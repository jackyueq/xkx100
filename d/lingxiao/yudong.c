// Room: /d/lingxiao/yudong.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��");
	set("long",@LONG 
���˵����ı������λõ�����һ������ô������������������á�
�������ڣ����۶��ڶ�����ȫ��ī�̵���ʯ����������ϸ�������Ǻ���
֮�񡣾�����Ȩ��֮�ң�������Ҳ���˲���ĲƸ���һ�����ư��ĺ�
���񣬾͹�һ���е��˼ҹ���һ���ӡ����ǣ������������˵ģ�������
�����̨(table)����Ȼ������һ�����ӣ���ɢ�������Ĺ����յ���
�ҽ��̡�
LONG);
	set("had_yujing", 1);
	set("exits",([ /* sizeof() == 1 */
		"out" : __DIR__"wave", 
	])); 
	set("item_desc", ([
		"table" : "����һ��������Ȼ�гɵ���̨�����г��ֳ���ֵ�ͼ�Ρ�
������Ȼ������һ������(zhuzi)��\n",
		"zhuzi": "����һ�����飬��ɢ�������Ĺ����յ����ҽ��̡�\n",
	]));
	
	set("coor/x", -31040);
	set("coor/y", -8950);
	set("coor/z", 100);
	set("no_clean_up", 0);
	setup();
}

void init()
{	
	add_action("do_take", "take");
	add_action("do_take", "qu");
	add_action("do_take", "jian");
	add_action("do_take", "pick");
}

int do_take(string arg)
{
	object baoyu, me=this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="zhuzi" )
	{
		if (query("had_yujing"))
		{
			
			message_vision("$N����Ĵ�ʯ̨�ϼ����������\n", me);
			baoyu = new(__DIR__"obj/yujing");
			baoyu->move(me);
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"���˱���������\n"NOR, users());
			set("had_yujing", 0);
			return 1;
		}		
		message_vision(
"$N����ȥȡ���ŷ��ֱ������ʯ���̻���һ̲ˮ����������ͱ�����ȡ����...��\n", me);
		return 1;
	}
	return 0;
}
