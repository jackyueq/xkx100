// Room: /d/chengdu/dongjie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ֹᴩ�ɶ����С����������ؽֶ�����Ǯ���Ƶľ�¥����
�ݣ������ֳ�Ϊ����ʳ�֡�����������������ֳ̼�Ⱥ���������ﳵ��
�������������У�ҹ���ǹ���£��ƻ�ͨ�����ϱ߱��ǳɶ���������ҵ
���ģ�����·�������и���ջ��
LONG	);
	set("outdoors","chengdu");
	set("exits", ([
		"west"  : __DIR__"guangchang",
		"east"  : __DIR__"dongjie2",		
		"north" : __DIR__"kedian",
		"south" : __DIR__"chunxilu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
