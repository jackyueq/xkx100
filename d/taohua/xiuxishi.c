// Room: xiuxishi.c

inherit RESTROOM_IN;

void create()
{
        set("short", "�һ���");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("coor/x", 8970);
	set("coor/y", -2990);
	set("coor/z", 0);
  set("door_name","��");
	set("door_dir","east");
	set("force_name","÷����");
  set("outroom",__DIR__"siguoshi");
	setup();
}
