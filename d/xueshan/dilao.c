//      dilao.c ����

inherit ROOM;

void create()
{
        set("short","����");
        set("long", @LONG
����һ����������ʪ���η�����е���ֵ�������᲻ʱ����һ��
����ȴ��ôҲ�Ҳ�������? 
LONG );
        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70040);
	set("coor/y", -19890);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
