//Edited by fandog, 02/15/2000

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�ļ���");
	set("long", @LONG
�����ļ���������һ�����˲�֪�������ʽ���Ⱦ����人һ����
���������Ŀ����Ƕ��������ﳢ�������������ֺ��ģ����������ǵǡ�
����Ļ��������ȥ��æ���к����ˡ�ǽ�Ϲ��ż۸�����(paizi)��
LONG);
	set("exits", ([
		"west"  : __DIR__"hzjie1",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("item_desc", ([
		"paizi" : "
���ϱ�ȹ��(Donggua)        ����������
��ͷܽ��(Houtou)           ����������
������(Longfeng)           ����������
����������(Tianma soup)    ����������
���������(Wuchang yu)     ����������
�㹽�հ���(Xianggu banli)  ����������
���������(Zhenzhu soup)   ����������\n",
        ]));

	set("coor/x", -1490);
	set("coor/y", -2100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}