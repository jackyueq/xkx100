// garden.c

inherit ROOM;
void create()
{
	set("short","��԰");
	set("long",@LONG
�����ɷ�ۺ��һ��԰�ӣ�ͥԺ���ģ����ֻ������ǲ��١��˴��ߺ�
����Ҳ��ƽ��������پԼ��ɷ����������������ͨ�����������ң�������
����
LONG);
	set("exits",([
		"east"      : __DIR__"woshi",
		"south"     : __DIR__"songfengguan",
	]));
	set("outdoors", "qingcheng");
        set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -820);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
 