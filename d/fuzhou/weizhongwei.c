// jiulou.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "ζ��ζ");
	set("long", @LONG
����¥��¥����Բ�������˲�֪������ĸ�ʽ���˾��Ǹ���һ����
���κ������Ƕ�һ���������ﳢ���������������ֺ��ļ����˸�ʽ��
�ȡ���С��������ȥ��æ���к����ˡ�
    ǽ�Ϲ��ż۸�����(paizi)��
LONG);
	set("exits", ([
		"west"  : __DIR__"nandajie",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
	]));
	set("item_desc", ([
		"paizi" : "
����ǽ(Fotiaoqiang)   ����������
�����Ͼ�(Jiuping)     ����������\n",
	]));
	set("coor/x", 1850);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
