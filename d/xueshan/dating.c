// dating.c ����

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���������ڵĴ�������λ�е��ĸ�ɮ�ڸ������ۡ���������������
�䣬�������档
LONG );
	set("exits",([
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang2",
		"northeast" : __DIR__"chanshi",
		"southeast" : __DIR__"cangjing",
		"northwest" : __DIR__"cangjingge",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/fawang" :1,
	]));
	set("coor/x", -70000);
	set("coor/y", -19890);
	set("coor/z", 130);
	setup();
}