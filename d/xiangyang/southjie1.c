// Room: /d/xiangyang/southjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣�ϱ߾���
��ȸ�ţ�����������㳡��������Ǯׯ���������������ڵ�Ψ
һһ��ѧ�á���Ȼ����ս�𲻶ϣ�����������ѧ���ﴫ��ѧ��
�����ʵض�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"xuetang",
		"west"  : __DIR__"qianzhuang",
		"south" : __DIR__"southjie2",
		"north" : __DIR__"guangchang",
	]));
	set("coor/x", -500);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}