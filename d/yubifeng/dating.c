// /yubifeng/dating.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @long
�������������ĽǸ�����һ���̿�����Ͼ��й���һ��ľ���
����д��إ�������֣��������ɶ����������޵��֣����˼�����������
��Ӣ�ۡ����Ͽ��ǡ�ϣ��������֮�����¿��ǡ��������˷���������
�����Ϳѻ����
long );
	set("exits", ([
		"south" : __DIR__"changlang",
		"west"  : __DIR__"zoulang1",
		"east"  : __DIR__"zoulang2",
	]));
	set("objects", ([
		__DIR__"npc/duximeng" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6120);
	set("coor/y", 5180);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
