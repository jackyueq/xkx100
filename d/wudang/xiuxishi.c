// Room: xiuxishi.c ��Ϣ��
// By Marz

inherit RESTROOM_IN;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("coor/x", -2030);
	set("coor/y", -910);
	set("coor/z", 90);
  set("door_name","��");
	set("door_dir","south");
	set("force_name","����Ϫ");
  set("outroom",__DIR__"donglang2");
	setup();
}
