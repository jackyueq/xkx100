// Room: /d/huashan/luoyan.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�Ϸ���������壬�ǻ�ɽ��߷塣��ͷ��̼��࣬�硰̫����ͷ����
���������족����������ǡ��ȣ����Ի���֮�ߡ��������ܣ��������¡�
��׼ʫ��Ի��ֻ�������ϣ�����ɽ���룻��ͷ���ս������װ��Ƶ͡���
˵���ʱ�����ʿ���Ҿ������������̫��������گ������ɽ���٣�
����������д��лگ��˵����һƬҰ�Ķ���������ס�����س�گ�ݽ̵�
������������ʾ��Ը��ɽ���١�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"enter"     : __DIR__"xiaofang",
		"northdown" : __DIR__"zhandao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -860);
	set("coor/y", 120);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
