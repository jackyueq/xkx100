// Room: /d/nanshaolin/chanfang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������о���������������һ��С��¯�����������̴���ɢ������
�������䷿�ڡ�����͸������������ʯ���ϣ����������γɸ���ҫ�۵�
���������еĵ���ɢ���ż������ţ����������ɮ������Ŀ���������ϡ�
LONG
	);
	set("exits", ([
                "south" : __DIR__"chanfang-1",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
