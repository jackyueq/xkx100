// Room: /d/quanzhou/dxbaodian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���۱���");
	set("long", @LONG
ʯͥ��ͷ�����Ǵ��۱���ഫ����֮�գ�������Ʈ�Ƹǵأ�����
�ơ����ƴ������϶�������Ŷ�ʮ���������ġ����졹(fairies)�� 
�������룬չ�����ɡ����ڰ�������������м��������ڵġ�����
�����ͼ�Ĳ�����������Ϊ�Ϸ����������������ӷ𣬶�������
�𣬱����ɾͷ𡣺�������̬�����ʮ���޺���
LONG );
	set("item_desc", ([
		"fairies" : "
�еķ����ֳ�����������е������ķ��ı����������
����֮�䣬���˷·�����һ�����ִ����������Լ���ʡ�\n",
	]));
	set("exits", ([
		"south" : __DIR__"tianwangdian",
		"north" : __DIR__"yuetai",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
