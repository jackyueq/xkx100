//  Room:  /d/changan/club3
inherit  ROOM;

void  create  ()
{
    set  ("short",  "������");
    set  ("long",  @LONG
����һ��������Ĵ������������м���һ��Բ�ε����ӡ�������
�����˸��ֹ�棺�л����ģ������Ҿߵģ����������Ļ����Ҵ��ƴ�
���Ĺ�档���Ķ����������и��ţ����洫�����������������ˣ�����
�Ľ�����
LONG);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
        "down":  __DIR__"clubpoem",
        "west":  __DIR__"majiang",
        "east":  __DIR__"xiangqishi",
        "south": __DIR__"qishi",
        "north": __DIR__"piggy",
    ]));
    set("no_clean_up", 0);
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 30);
	setup();
    replace_program(ROOM);
}
