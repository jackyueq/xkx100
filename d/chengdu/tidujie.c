// Room: tidujie.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ᶽ��");
	set("long", @LONG
�ᶽ�־�����Ϊͨ���ᶽ������������һ���������˺��٣�������
�ľ͸��Ǿ����ˡ��ᶽ���˺����������벻���ģ����˺ö����������
�������������ﶼ��������̤�롣
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"nanjie2",
		"north" : __DIR__"tidugate",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	]));
	set("coor/x", -8040);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
