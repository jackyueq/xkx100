// Room: /qingcheng/yuanyangjing.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "ԧ�쾮");
	set("long", @LONG
���������ԧ�쾮��һ��һԲ��Ȫ����ͨ��Բ��ˮ�ǣ�����ˮ
�塣��ˮһ��һ����������ʫԻ����˭֪�Ͻ����ɿͣ�Ҳ��������
̬ͬ����
LONG );
        set("outdoors","qingcheng");
        set("resource/water", 1);
	set("exits", ([
		"east"     : __DIR__"shangqing",
	]));
        set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -880);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}