// Room: /d/taishan/jin18.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ʮ����");
	set("long", @LONG
�����ڽ�ʮ�����ϣ�̧ͷֻ�ܿ���ǰ����˵�Ь�ף���ͷ������ֻ
���������˵ķ�����������ÿ��ʮ������Ҫ��һ��Ϣ���������о�����
�գ���Ӱ��ͷ�����߱�ͺ��������΢Ц����ӭ�ͷ�
����ʮ�����Ҳ㶸�����ڲ�������������߽�һ����˸���ʮ���̡�
ʫ�����ε���ǧ�ɣ�����ʮ���̡��������������϶�йۡ���������
�������������͡���ƽ��ʤ�ߣ����չ��̺�����
LONG );
	set("exits", ([
		"northup"   : __DIR__"nantian",
		"southdown" : __DIR__"shengxian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 760);
	set("coor/z", 190);
	setup();
	replace_program(ROOM);
}
