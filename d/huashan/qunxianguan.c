// Room: /d/huashan/qunxianguan.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Ⱥ�ɹ�");
	set("long", @LONG
�����ǻ�ɽ������֮�����صأ�ǽ�Ϲ��Ż�ɽ�����������˵Ļ���
��ɽ��һ���ش����Ƕ���������С�����Ҳ�ǻ�ɽ���ӽ���ϰ��֮�ء�
���߾��ǻ�ɽ��������Ⱥ�ľ�����������Ϊ������
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south": __DIR__"square",
		"north": __DIR__"buwei1",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/yue-buqun": 1,
	]));

	set("coor/x", -860);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
