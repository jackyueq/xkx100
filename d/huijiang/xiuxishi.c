// Room: /d/huijiang/xiuxishi.c
// Last Modified by winder on Sep. 12 2001

inherit RESTROOM_IN;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿������������ֻ���м����һ����ʰ������
�����Ĵ󴲣����ž�������˯����
LONG );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -50070);
	set("coor/y", 9130);
	set("coor/z", 10);
  set("door_name","��");
	set("door_dir","north");
	set("force_name","����");
  set("outroom",__DIR__"zoulang2");
	setup();
}
