inherit ROOM;
void create()
{
        set("short", "�ƺ�����");
        set("long", @LONG
������Ƕ����������ƺ��ˣ�������ȥ����ɽ��Ұ��
������������Ū�����Լ����ںγ�������������ԼԼ��
һ���ٲ�������£�
LONG  );
        set("exits",([
          "north": __DIR__"pubu",
          "south": __DIR__"yunhai12",
        ]));
	set("coor/x", -6200);
	set("coor/y", -1170);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}