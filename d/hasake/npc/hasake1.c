inherit NPC;
void create()
{
        set_name("�����˸�Ů", ({ "hasake", "woman"}));
        set("gender", "Ů��");
        set("age", 25);
        set("long", "һλ����ÿ͵Ĺ������帾Ů��\n");
        set("attitude", "friendly");
        set("combat_exp", 500);
        set("str", 18);
        set("int", 18);
        set("con", 18);
        set("dex", 17);
        set("max_qi", 140);
        set("max_jing", 140);
        set("neili", 100);
        set("max_neili", 100);
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5);
        set("inquiry", ([
            "����" : "�����ǲ�ԭ��һ�����·�Ļ���\n",
            "������" : "�������⺢�ӣ����úͰ���һ����������Ҳ���úá�\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"�����˸�Ů��: ����������ɣ������ԭ����������ҡ�\n",
        }) );
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/shuinang");
}
