// /yubifeng/damen.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @long
ת���˼���ѩ�ɣ�ֻ��ǰ��һ���忪�伫���ʯ�ݣ���ǰ�ݺ���
��ѩ��������д�š���ʷ�ɽׯ���������֣��˴�����Ắ�����¼��ѣ�
������֪��ׯ�����˶��ٵ���˼�����ڴ˽������ʯ�ң�������������
���档
long );
	set("exits", ([
		"west"  : __DIR__"fengding",
		"enter" : __DIR__"changlang",
	]));
	set("objects", ([
		__DIR__"npc/caoyunqi" : 1,
		__DIR__"npc/zhouyunyang" : 1,
		__DIR__"npc/ruanshizhong" : 1,
		__DIR__"npc/yinji" : 1,
	]));
	set("outdoors", "yubifeng");
	set("coor/x", 6120);
	set("coor/y", 5170);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
