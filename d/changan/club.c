// /d/changan/club.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "�����ַ�");
        set  ("long",  @LONG
�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ�����͸�����
�֡����������Ŀ����д�ٹ��ˣ��������������ã��˼����ĵ����ӣ�
�����Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���ɮ�˻��ʿ��
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "south" :  __DIR__"eastroad2",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
