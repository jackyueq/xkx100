// zhandao.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����ջ��");
	set("long", @LONG
ջ������б�壬�ϸ���ʯ�壬����˴硣���˾��ڣ�������ڡ�
���������ϣ�ֻ��ɽ���Х������ŭ��Զ��ż��һ����������˻����
ʹ��ë���Ȼ��̤�����յ�ջ����������������Ϣ����������Ų������
�ܹ�ȥ��
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"luoyan",
		"northdown" : __DIR__"sgyhole",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -860);
	set("coor/y", 130);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
