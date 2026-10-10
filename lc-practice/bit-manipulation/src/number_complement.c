int mask_length(int num) {
    int num_post_shift = num;
    int length = 0;

    while (num_post_shift != 0) {
        num_post_shift = num_post_shift >> 1;
        length++;
    }

    return length;
}

int create_mask(int length) {
    return (1u << length) - 1u;
}

int findComplement(int num) {
    if(num < 1) {
        return -1;
    }
    int length = mask_length(num);
    return num ^ create_mask(length);
}
