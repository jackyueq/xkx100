//Edited by fandog, 01/31/2000
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIR"���"NOR);
	set ("long", @LONG
������չ�ڴ�֮�е�һ��Сʯɽ���ٽ����ͱ��Ͽ��С���ڡ���
�����֣��ഫ������ʱ��������顣����ʱ��Ȩ�������ϱ�����������
�𹥴��Ʋܲٵİ�ʮ�������Ѳܾ���ˮ��������һȼ��������ʱ����
�һ����ܣ��Ѵ��ϰ���ʯ���յ�ͨ�죬�Ӵˣ����Ǿͽ���������Сʯ
ɽΪ����ڡ���
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"south" : __DIR__"huanghelou",
		"north" : __DIR__"matou2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
